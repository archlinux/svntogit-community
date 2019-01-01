# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgname=parallel
pkgver=20181222
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='http://www.gnu.org/software/parallel/'
license=('GPL3')
depends=('perl' 'procps')
source=(https://ftp.gnu.org/gnu/$pkgname/$pkgname-$pkgver.tar.bz2{,.sig}
        remove-citation-nagging.patch)
sha1sums=('0eeb7f0503dc55c862f1c12d9d394f21e52764ae'
          'SKIP'
          'c33163602d9aabfe8a54c58a57f478642274f111')
validpgpkeys=('CDA01A4208C4F74506107E7BD1AB451688888888')

prepare() {
  cd parallel-$pkgver
  patch -p1 <"$srcdir"/remove-citation-nagging.patch
}

build() {
  cd parallel-$pkgver
  ./configure --prefix=/usr
  make
}

package() {
  cd parallel-$pkgver
  make DESTDIR="$pkgdir/" install
}

# vim:set ts=2 sw=2 et:
