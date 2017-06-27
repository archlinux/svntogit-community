# vim:set ts=2 sw=2 et:
# $Id$
# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org

pkgname=par2cmdline
pkgver=0.7.3
pkgrel=1
pkgdesc='A PAR 2.0 compatible file verification and repair tool'
url='https://github.com/BlackIkeEagle/par2cmdline'
license=('GPL2')
arch=('i686' 'x86_64')
depends=('gcc-libs')
source=("https://github.com/Parchive/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz"
        "https://github.com/Parchive/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.sig")
sha512sums=('7e6cb8efd43b704df7466f7801e62dfe7552b37bfaf88a09010edd501fd3fbeecee6458f0380d0999e67b0a1c62ef44326748e6066ba5203b667967f2f4822db'
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
