# Maintainer: Torsten Keßler <tpkessler at archlinux dot org>
# Contributor: acxz <akashpatel2008 at yahoo dot com>
pkgname=half
pkgver=2.2.0
pkgrel=2
pkgdesc="Half-precision floating-point library"
url="http://half.sourceforge.net/"
arch=('x86_64')
license=('MIT')
source=("$pkgname-$pkgver.zip::https://sourceforge.net/projects/$pkgname/files/$pkgname/$pkgver/$pkgname-$pkgver.zip/download")
sha256sums=('1d1d9e482fb95fcd7cab0953a4bd35e00b86578f11cb6939a067811a055a563b')

package() {
    install -Dm644 "$srcdir/include/half.hpp" "$pkgdir/usr/include/half/half.hpp"
    install -Dm644 "$srcdir/LICENSE.txt" "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
