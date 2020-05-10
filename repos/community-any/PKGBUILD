# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Timothy Redaelli <timothy.redaelli@gmail.com>
# Contributor: Vianney le Clément <vleclement AT gmail·com>
# Contributor: Peter Simons <simons@cryp.to>

pkgname=parallel
pkgver=20200322
pkgrel=1
pkgdesc='A shell tool for executing jobs in parallel'
arch=('any')
url='https://www.gnu.org/software/parallel/'
license=('GPL3')
depends=('perl' 'procps')
source=(https://ftp.gnu.org/gnu/$pkgname/$pkgname-$pkgver.tar.bz2{,.sig}
        0001-Remove-citation-things.patch
        0002-Remove-GNU-branding.patch)
sha1sums=('073ff02f6140f8a7ccfcd695e09895a6e9720559'
          'SKIP'
          '8b6c47736cd827f3a826dbceb03925678c3d2080'
          '0f61b5e584063daa7c7be08734fdec10acba36d6')
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
