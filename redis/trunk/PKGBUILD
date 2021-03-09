# Maintainer: Andrew Crerar <crerar@archlinux.org>
# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Jan-Erik Rediger <badboy at archlinux dot us>
# Contributor: nofxx <x@<nick>.com>

pkgname=redis
pkgver=6.2.1
pkgrel=1
pkgdesc='An in-memory database that persists on disk'
arch=('x86_64')
url='https://redis.io/'
license=('BSD')
depends=('jemalloc' 'grep' 'shadow' 'systemd-libs')
# pkg-config fails to detect systemd libraries if systemd is not installed
makedepends=('systemd' 'openssl')
backup=('etc/redis.conf'
        'etc/logrotate.d/redis')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/antirez/redis/archive/${pkgver}.tar.gz"
        redis.service
        redis.sysusers
        redis.tmpfiles
        redis.logrotate
        redis.conf-sane-defaults.patch
        redis-5.0-use-system-jemalloc.patch)
sha512sums=('79108a10911698aef64412792574e75d8b5e41fa45e7631a9cd39bc704d2fce8648a494f25868c4cf6775afa8b56287a21cafbaee8c306803a2ddcb2b355ff7e'
            'a3793d84f4da8eae68e0deda60ce2d7874a98562cd56be0bce07a54de99bad9ebba8db06051310a86587b6e8ddfcf401f6e1b089161981c68e25b6a63c56b52c'
            '2227dfb41bf5112f91716f011862ba5fade220aea3b6a8134a5a05ee3af6d1cca05b08d793a486be97df98780bf43ac5dc4e5e9989ae0c5cd4e1eedb6cee5d71'
            '68f7bc12e3b95cb199b71255c6aa5bfaa431fbabbc7d2308e54347c0d35e6d8091c4a79a5a6b56494ab3a294f9389e3ec63902931920862f60b1ffe77222eeeb'
            'df11492df0458b224f75fff31475d39b85116cba6deb06d80d0fd8c467d221db51a2a8f5fc5d2e3e8239c0718e1cf5dc12e99cac9019cb99d3f11835ad00aa5d'
            '9c43c858270d72cf5251d8226b0113f83c1749ad39b8ba286b7f90f05ad666d62ae7e17dc41a2d0a7bec833d65c98c7a3f12a30a93a28f0b1ab1c5a9e9a04a73'
            '0acb08a6e0eaba239db7461bcfeddfbe0c1aaa517dc33c3918c9e991a1d5067cfe135b7f75085caade8c3ababd51ec9cefcc4120f57818bea1f7029a548a7732')

prepare() {
  cd $pkgname-$pkgver
  patch -Np1 < ../redis.conf-sane-defaults.patch
  patch -Np1 < ../redis-5.0-use-system-jemalloc.patch
}

build() {
  make BUILD_TLS=yes \
       USE_SYSTEMD=yes \
       -C $pkgname-$pkgver
}

package() {
  cd $pkgname-$pkgver
  make PREFIX="$pkgdir"/usr install

  install -Dm644 COPYING "$pkgdir"/usr/share/licenses/redis/LICENSE
  install -Dm644 redis.conf "$pkgdir"/etc/redis.conf
  install -Dm644 ../redis.service "$pkgdir"/usr/lib/systemd/system/redis.service

  # files kept for compatibility with installations made before 2.8.13-2
  install -Dm644 ../redis.logrotate "$pkgdir"/etc/logrotate.d/redis

  ln -sf redis-server "$pkgdir"/usr/bin/redis-sentinel

  install -Dm644 "$srcdir"/redis.sysusers "$pkgdir"/usr/lib/sysusers.d/redis.conf
  install -Dm644 "$srcdir"/redis.tmpfiles "$pkgdir"/usr/lib/tmpfiles.d/redis.conf
}
