## Proje Akışı

T0 - 21.09.2020

- 1. Hafta : Sözleşme isterlerine göre uygun yazılım ve arayüz platformları, yazılım dili belirlenir. Gerekirse sabit ayaklı düzenek kurulur. Işık kaynağı eklenir. (Evde kurulacaksa düzeneğe ve ışık kaynağınına karar vermemiz gerekiyor.)
- 2. Hafta: Kamera özellikleri çalışılır, bağlantısı yapılır. Düzenek şartlarında en iyi görselleri yakalamak için çalışma yapılır. İlk çekimlerle bir veri seti oluşturulur. (daha fazla örnek talep etmemiz gerekli gibi duruyor)
- 3-4-5-6 Haftalar: Literatür taraması. Yazılım tasarımı. Çeşitli Algoritmaların denenmesi. Gerekirse tekrar veri setlerinin oluşturulması.
- 7. 8. Haftalar: İlk raporlama. Basit bir arayüz programı ile ilk sunuşun yapılması. Sonuçların değerlendirilmesi. Müşteri ile toplantı. Yeni yol haritasına göre literatür taraması, veri seti değişimleri
- 9. 10. Haftalar: Yazılımın sonlandırılması, (varsa) arayüzün sonlandırılması. Son raporlama ve sunum. Yazılım, veri seti ve dokümanların düzenlenip paylaşılmasın.

(3 ayı tamamlayan geri kalan zamanı beklenmedik sarkmalar ve gecikmeler için tolerans olarak düşündüm.)

## ODTÜ Proje Sorular

- Proje dahilinde ne tür Ar-Ge çalışmaları, aşamaları planlanmıştır?

 Projede müşteri tarafından sağlanan yüzey kusurları bulunan plastik parçalarda, genellikle nokta biçimindeki kusurları tespit etmek amacı taşıyan bütün bir sistem tasarlanması amaç edinilmiştir. Çalışmalar donanım düzeneği kurulması, kusur tespit algoritmaları tasarımları ve kullanıcı arayüzünü kapsamaktadır. Ar-Ge odağı kusur tespiti üzerinde olacaktır.

- Projenin teknik detayları nelerdir? / Hangi algoritmalar, yaklaşımlar, hesaplama yöntemleri, methodlar, vb. kullanılacaktır?

Metotların detayları tasarım aşamasında şekillenecek olsa da genel olarak ön işleme (histogram eşitleme, blur vb.) tabi tutulan görsellere klasik görüntü işleme algoritmaları (median filtre, Canny filtresi, Laplacian filtresi vb.) ile derin öğrenme araçları (GAN vb.) uygulanması planlanmaktadır.

- Projede ihityaç duyulan altyapı unsurları nelerdir? / Kullanılacak laboratuvarlar, test alanları, yazılım platformları, vb. nelerdir?

Kusurların bulunduğu nesne ve kamerayı sabit tutacak, ince ayarlamalara imkan verecek mekanik düzeneğe gerek duyulacaktır. Ortam ışıklandırması mümkün olduğunca kontrollü (gerekirse kapalı perde ve ayarlı ışık kaynağı ile) olmalıdır. Donanım olarak 5 Megapiksel bandında endüstriyel kamera, makro çekim için uygun lens (ör; 1:1.6) ve işlem birimi olarak bilgisayar kullanılacaktır.

Windows işletim sistemine masaüstü uygulama şeklinde verilecek ürünümüzün C++ yazılım dilinde tasarlanması planlamıştır. 

- Proje çıktısı ya da benzerleri yurtiçi veya yurtdışı sektörlerde mevcut mudur?

Benzer çıktılar dünyada mevcut; fakat, genel kullanıma tabidir. Daha açık olmak gerekirse, bu yazılımlar her yüzeyde, bir çok formdaki kusurları bulmaya yöneliktir. Bizim amacımız müşterinin isterleri ve ürün özelliklerine ait hızlı ve yüksek doğruluklu bir çözüm getirmektir.

- Mevcut ise; fiyat-performans avantajı, malzeme kullanımı, taşınabilirlik, teknik özellikler, farklı fonksiyonlar, vb. açılardan proje çıktısının yenilikçi yönünü nedir?


- Mevcut değil ise; proje çıktısının avantajları, gereklilikleri, sektörde öncülük edebileceği yaklaşımlar veya yeni projeler nelerdir?

Proje çıktısı müşteriye ait plastik örneklerde, yine müşterinin tanımladığı kusurları hızlı ve doğru şekilde bulmaya yönelik bir özellik taşımaktadır. Sonraki aşamalarda farklı müşterilere tasarlanacak yazılımların önünü açabilir. Yine genel kullanıma kaymadan, her projeye özel yaklaşımlar geliştirmek avantajını taşımaktadır.

- Proje çıktısı benzeri ürünler yurt içi pazarda mevcut mudur? / Hedeflenen yurt içi pazar payı nedir? / Firmanın yurt içi rakipleri hangi kurumlardır ve rakiplerin pazardaki durumu nedir? / Ne kadar sürede, hangi yöntemlerle hedef pazar payına ulaşılması planlanmaktadır?


- Proje çıktısının ihracat potansiyeli var mıdır? / Proje çıktısı benzeri ürünler yurt dışı pazarda mevcut mudur? / Yurt dışında potansiyel oluşturabilecek pazarlar, ülkeler hangileridir? / Proje çıktısının ihracatı planlanmakta mıdır?"

Müşteri firma yurtdışı partnerli bir firma olduğu için şirket içinden yurtdışına aktarılması mümkün. BU partner Alman menşeilidir. Biz ihracat planlaması yapmadık.
