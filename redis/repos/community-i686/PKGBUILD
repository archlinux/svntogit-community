# Maintainer: Jan-Erik Rediger <badboy at archlinux dot us>
# Contributor: nofxx <x@<nick>.com>

pkgname=redis
pkgver=1.2.6
pkgrel=1
pkgdesc="Advanced key-value store"
arch=('i686' 'x86_64')
url="http://code.google.com/p/redis"
license=('BSD')
depends=('bash')
makedepends=('gcc>=3.1' 'make' 'pkgconfig')
source=("http://redis.googlecode.com/files/${pkgname}-${pkgver}.tar.gz"
        "redis.d")
md5sums=('0c5355e57606523f9e8ce816db5e542f'
         '7de0d0e70cef571a2da9a431e4b40917')

build() {
    cd "$srcdir/${pkgname}-${pkgver}"
    CFLAGS="$CFLAGS -std=c99" make || return 1

    sed -i 's|daemonize no|daemonize yes|;s|dir \./|dir /var/lib/redis/|;s|logfile stdout|logfile /var/log/redis.log| ' $srcdir/${pkgname}-${pkgver}/redis.conf

    install -D -m755 "$srcdir/${pkgname}-${pkgver}/redis-server" "$pkgdir/usr/bin/redis-server" || return 1
    install -D -m755 "$srcdir/${pkgname}-${pkgver}/redis-cli" "$pkgdir/usr/bin/redis-cli" || return 1
    install -D -m755 "$srcdir/${pkgname}-${pkgver}/redis-benchmark" "$pkgdir/usr/bin/redis-benchmark" || return 1

    install -D -m755 "$srcdir/${pkgname}-${pkgver}/COPYING" "$pkgdir/usr/share/licenses/redis/COPYING" || return 1

    install -D -m755 "$srcdir/${pkgname}-${pkgver}/redis.conf" "$pkgdir/etc/redis.conf" || return 1
    install -D -m755 "$srcdir/redis.d" "$pkgdir/etc/rc.d/redis"
}
