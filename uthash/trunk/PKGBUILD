# Maintainer: Santiago Torres-Arias <santiago@archlinux.org>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Michael Frey <mail@mfrey.net>
pkgname=uthash
pkgver=2.3.0
pkgrel=1
pkgdesc="C preprocessor implementations of a hash table and a linked list"
arch=('any')
url="https://troydhanson.github.io/uthash/"
license=('BSD')
source=("$pkgname-$pkgver.tar.gz::https://github.com/troydhanson/$pkgname/archive/v$pkgver.tar.gz")
sha256sums=('e10382ab75518bad8319eb922ad04f907cb20cccb451a3aa980c9d005e661acc')

package() {
  cd "${srcdir}/${pkgname}-${pkgver}/src"
 
  # create directory for header files 
  install -dm755 "${pkgdir}"/usr/include/

  # install header files in /usr/include
  for h in *.h; do
      install -m 644 ${h} "${pkgdir}"/usr/include/
  done

  # install license file
  install -D -m644 ../LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
