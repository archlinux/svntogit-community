# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgname=parallel
pkgver=20191122
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
depends=('perl' 'procps')
source=(https://ftp.gnu.org/gnu/$pkgname/$pkgname-$pkgver.tar.bz2{,.sig}
        0001-Remove-citation-things.patch
        0002-Remove-GNU-branding.patch)
sha1sums=('0cfb88b080c6711d2eaa8960e4fc8cc22c4501ef'
          'SKIP'
          '50a4e5fe39ab1bd39e0ee0ee2f1faced0c6c2262'
          'd46fc3ac0cfffcc0a5595a19c763ed5663b4f9d3')
validpgpkeys=('CDA01A4208C4F74506107E7BD1AB451688888888')

prepare() {
  cd parallel-$pkgver
  patch -p1 <"$srcdir"/0001-Remove-citation-things.patch
  patch -p1 <"$srcdir"/0002-Remove-GNU-branding.patch
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
