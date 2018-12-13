# vim:set ts=2 sw=2 et:
# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org

pkgname=par2cmdline
pkgver=0.8.0
pkgrel=2
pkgdesc='A PAR 2.0 compatible file verification and repair tool'
url='https://github.com/BlackIkeEagle/par2cmdline'
license=('GPL2')
arch=('x86_64')
depends=('gcc-libs')
source=("https://github.com/Parchive/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz"
        "https://github.com/Parchive/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.sig")
sha512sums=('7dc19d18d375c1ec62f438613fec0008515e325a1387feb9c9f92d84b5bfa955911459147732ead4c20ce7e77dc6d7d22da5b388fb572026aa431b28252b5fcf'
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
