# Maintainer: Andrew Crerar <crerar@archlinux.org>
# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Jan-Erik Rediger <badboy at archlinux dot us>
# Contributor: nofxx <x@<nick>.com>

pkgname=redis
pkgver=6.2.2
pkgrel=1
pkgdesc='An in-memory database that persists on disk'
arch=('x86_64')
url='https://redis.io/'
license=('BSD')
depends=('jemalloc' 'grep' 'shadow' 'systemd-libs')
# pkg-config fails to detect systemd libraries if systemd is not installed
makedepends=('systemd' 'openssl')
backup=('etc/redis/redis.conf'
        'etc/redis/sentinel.conf')
install=redis.install
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/redis/redis/archive/${pkgver}.tar.gz"
        redis.service
        redis-sentinel.service
        redis.sysusers
        redis.tmpfiles
        redis.conf-sane-defaults.patch
        redis-5.0-use-system-jemalloc.patch)
sha512sums=('0aa38612173ccf601f6ef6c41f6d4cf997c67b369af07b8a2600f611e992955443bd7ce0b3f42ed80dccfbe16f0c019822b01949a60b4fee63c0747bd693996b'
            '749c5eecfd6cd2ed949302672c20a7972dbef3a4b971ed569eb064362d7f20434b5c39077f665e178394158b5200375bc2e56614682fa08dbf99e868a9b75783'
            '2314c26920f5f0989fb98622f594b621a0b5035525146263da3fdfe640257118e03fc1903c15a62bcd4fbf260e0dcbf9249088292323739a607a11c9630795bf'
            '2227dfb41bf5112f91716f011862ba5fade220aea3b6a8134a5a05ee3af6d1cca05b08d793a486be97df98780bf43ac5dc4e5e9989ae0c5cd4e1eedb6cee5d71'
            '6a817024df70213205159de8350c684684d7dbda568c35a0a3d654bab0b91ec62d60b1a2aac6e1ffbe24040df4033b37a77361357834c572759f2d3c76d16ac0'
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
  install -Dm644 -t "$pkgdir"/etc/redis redis.conf sentinel.conf
  install -Dm644 -t "$pkgdir"/usr/lib/systemd/system/ ../redis.service ../redis-sentinel.service
  install -Dm644 "$srcdir"/redis.sysusers "$pkgdir"/usr/lib/sysusers.d/redis.conf
  install -Dm644 "$srcdir"/redis.tmpfiles "$pkgdir"/usr/lib/tmpfiles.d/redis.conf
}
