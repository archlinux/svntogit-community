# Maintainer: Andrew Crerar <crerar@archlinux.org>
# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Jan-Erik Rediger <badboy at archlinux dot us>
# Contributor: nofxx <x@<nick>.com>

pkgname=redis
pkgver=6.0.8
pkgrel=3
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
sha512sums=('792b2a21a123be82aa0b70f74f275ec12cdfe72bd34f0889fb9570efbf1f41ee0d9dc21400464321bdccb5fbe1dc5082ab08854f18e10a97135dd5fe92b5d798'
            '78c996636fc3f4d404a01fbbc63978ee4c3bce9bc7f5728e8ca14b013cabc7df73ff882ec7f4a2e0b5494faf0d1da5a3c5e9570bd579597b0fea03a9d8d066cc'
            '2227dfb41bf5112f91716f011862ba5fade220aea3b6a8134a5a05ee3af6d1cca05b08d793a486be97df98780bf43ac5dc4e5e9989ae0c5cd4e1eedb6cee5d71'
            '68f7bc12e3b95cb199b71255c6aa5bfaa431fbabbc7d2308e54347c0d35e6d8091c4a79a5a6b56494ab3a294f9389e3ec63902931920862f60b1ffe77222eeeb'
            'df11492df0458b224f75fff31475d39b85116cba6deb06d80d0fd8c467d221db51a2a8f5fc5d2e3e8239c0718e1cf5dc12e99cac9019cb99d3f11835ad00aa5d'
            'e60d1b213c3689f011490b47ef48d80b1240046585cae7ffe50fd9221350a24ee9c18ecbdee8e7d98d65f4af1a16809d1046f1246590aadaae5bcc5fda58d61b'
            '55b4085900c54fa7e7bf1c2bad7fba8cdbaf496a3f83b6d32fccb8aed5048cdde1690fea0485162dbb637e7fafb00a6b995908fa6db55e77854eb9f575b54d40')

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
