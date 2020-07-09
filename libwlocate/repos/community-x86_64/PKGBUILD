# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: sekret, mail=$(echo c2VrcmV0QHBvc3Rlby5zZQo= | base64 -d)
# Contributor: Bjoern Franke <bjo@nord-west.org>

pkgname=libwlocate
pkgver=0.1
pkgrel=3
epoch=1
pkgdesc="A shared library that can be used for location-based services"
arch=(x86_64)
url="https://sourceforge.net/projects/libwlocate"
license=(GPL)
depends=(wireless_tools glibc)
source=($pkgname-$pkgver.tar.gz::"https://github.com/openwifi-su/lwlocate/archive/v$pkgver.tar.gz")
sha256sums=('791899f4890fa88553b4e8417376187d7d533ead962f5fe51f598b6ed9a2c258')

build() {
  cd lwlocate-$pkgver/master
  make -f Makelib
  make
}

package() {
  cd lwlocate-$pkgver/master
  install -Dm644 libwlocate.so "$pkgdir"/usr/lib/libwlocate.so
  install -Dm644 libwlocate.h "$pkgdir"/usr/include/libwlocate.h
  install -Dm755 lwtrace "$pkgdir"/usr/bin/lwtrace
}
