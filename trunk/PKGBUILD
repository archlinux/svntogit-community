# vim:set ts=2 sw=2 et:
# $Id$
# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org

pkgname=par2cmdline
pkgver=0.7.4
pkgrel=1
pkgdesc='A PAR 2.0 compatible file verification and repair tool'
url='https://github.com/BlackIkeEagle/par2cmdline'
license=('GPL2')
arch=('x86_64')
depends=('gcc-libs')
source=("https://github.com/Parchive/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz"
        "https://github.com/Parchive/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.sig")
sha512sums=('3a0c001ac2c92ba0e8c12c493558fa6e13e760b0d744a4a674eb6efd62958f587254447757946a903965f8219458f1314ed9b57e6e42f78741d2f721d64d66e3'
            'SKIP')

validpgpkeys=(
  'DB2277BCD500AA3825610BDDDB323392796CA067'
)

build() {
  cd "$pkgname-$pkgver"
  ./configure --prefix=/usr
  make
}

check() {
  cd "$pkgname-$pkgver"
  make -j1 check
}

package() {
  cd "$pkgname-$pkgver"
  make DESTDIR="$pkgdir" install
}
