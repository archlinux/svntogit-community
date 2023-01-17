# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: T.J. Townsend <blakkheim@archlinux.org>

pkgname=minisign
pkgver=0.11
pkgrel=1
pkgdesc="A dead-simple tool to sign files and verify digital signatures"
arch=('x86_64')
url="https://github.com/jedisct1/minisign"
license=('custom:ISC')
depends=('libsodium')
makedepends=('cmake' 'git')
_commit=feefda7af87f64342bd07bf446ceb0467cbd0fb4 # git rev-parse $pkgver
source=("git+https://github.com/jedisct1/minisign.git?signed#tag=$_commit")
sha512sums=('SKIP')
validpgpkeys=(54A2B8892CC3D6A597B92B6C210627AABA709FE1) # Frank Denis

build() {
  cmake -B build -S $pkgname \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_BUILD_TYPE=None \
    -Wno-dev
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
