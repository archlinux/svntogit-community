# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Simon Lipp <sloonz+aur@gmail.com>
# Maintainer: Stefan Husmann < stefan-husmann@t-online.de>

pkgname=java-commons-logging
pkgver=1.2
pkgrel=3
pkgdesc="Wrapper interface for logging APIs in Java"
arch=('any')
url="https://commons.apache.org/logging/"
license=(APACHE)
depends=('java-runtime')
source=("http://apache.crihan.fr/dist/commons/logging/binaries/commons-logging-$pkgver-bin.tar.gz"
	"http://apache.crihan.fr/dist/commons/logging/source/commons-logging-$pkgver-src.tar.gz")
sha512sums=('8e511760b9e05d8265a062cd3d27573e1ba06d9e8414bc8917ba98f47adac8c74aadfb98db905d7370cfdadd08b3d0295509ba0c13f3e00f764b9c44a17d498a'
            '9f3761184950f2f13e85d8bc447709ab8be631dfd231b4f053f8147468db1bf71fb116ddba95e39f4afc4cf28c742e07d40c7a637f28004a60dc13935f9609f9')

build() {
  # TODO: build from sources
  true
}

package() {
  cd "$srcdir"/commons-logging-$pkgver/
  install -d "$pkgdir"/usr/share/java/commons-logging/
  install -m0644 commons-logging-$pkgver.jar \
    "$pkgdir"/usr/share/java/commons-logging/commons-logging.jar
}
