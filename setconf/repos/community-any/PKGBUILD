# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>

pkgname=setconf
pkgver=0.7.7
pkgrel=2
pkgdesc='Utility for easily changing settings in configuration files'
arch=(any)
url='https://setconf.roboticoverlords.org/'
license=(GPL2)
depends=(python)
source=("https://setconf.roboticoverlords.org/$pkgname-$pkgver.tar.xz"{,.asc})
validpgpkeys=('962855F072C7A01846405864FCF3C8CB5CF9C8D4')
sha256sums=('19315574540b3181fec31a4059b9e058381e0192317f153d181e7e7e2aa84d86'
            'SKIP')

package() {
  cd "$pkgname-$pkgver"

  install -Dm755 "$pkgname.py" "$pkgdir/usr/bin/$pkgname"
  install -Dm644 "$pkgname.1.gz" "$pkgdir/usr/share/man/man1/$pkgname.1.gz"
}

# getver: setconf.roboticoverlords.org
# vim: ts=2 sw=2 et:
