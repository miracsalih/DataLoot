## DataLoot / dataloot.cpp:

### `struct DataLoot`

`.dataloot` formatlı metinden, programın kolayca okuyabileceği yapıdır.

- **İlgili:** Bu yapıyı döndüren yapı sadece ``decode`` fonksiyonu.
- **Açılımı:**
    - **struct Variable:**
        - **std::string name:** Değişken adı.
        - **std::string data:** Değişken verisi.
    - **std::map<:**
        - **std::vector<string>:** Dizin yolu.
        - **std::vector<Variable>:** Veri yapısı.
    - **> variables:** Dizin yoluna göre veri yapısı.
    - **std::vector<std::string> error_here:** Hataları gösterir.
    - **bool error_found:** Hata olup olmadığı.

### `DataLoot decode(std::string& code)`

`.dataloot` formatlı metni derler.

- **Girdi:** Derlenecek `.dataloot` formatlı metin (`std::string`).
- **Çıktı:** Programın kolayca okuyabileceği yapı (`DataLoot`).
