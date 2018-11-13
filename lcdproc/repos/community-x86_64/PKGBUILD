# Maintainer: BlackEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Bernhard Walle <bernhard.walle@gmx.de>

pkgname=lcdproc
pkgver=0.5.9
pkgrel=2
pkgdesc="Utility to drive one or more LCD (and LCD-like) devices"
arch=('x86_64')
url="http://lcdproc.omnipotent.net/"
license=('GPL')
depends=('libftdi-compat')
makedepends=('g15daemon')
optdepends=(
    'perl: needed for some lcdproc tools'
    'g15daemon: needed if you want g15 support'
)
backup=(
    'etc/LCDd.conf'
    'etc/lcdexec.conf'
    'etc/lcdproc.conf'
    'etc/lcdvc.conf'
)
source=(
    "https://github.com/lcdproc/lcdproc/releases/download/v$pkgver/lcdproc-$pkgver.tar.gz"
    'lcdd.service'
)
sha512sums=('48e11a587570376b9524591f4c23deace9ac1609b83ba9e17f2a4e950d5598f8f88b580ca01c174ec9c2ef98b1eef7ac274c23ca3541d4d7ff918af0598c6a25'
            '33d08d9b5606b8b830cc652fe07a11ee4e7e50f9d257e412c70f64bfd02eaaa732f7124632cd459cece2526de635ef192f863889070533746232773b48b3064a')

build() {
    cd "$pkgname-$pkgver"
    ./configure \
        --prefix=/usr \
        --sbindir=/usr/bin \
        --sysconfdir=/etc \
        --enable-libusb \
        --enable-lcdproc-menus \
        --enable-stat-smbfs \
        --enable-drivers=all
    make
}

package() {
    cd "$pkgname-$pkgver"
    make DESTDIR="$pkgdir" install
    sed -e "s/server\/drivers\//\/usr\/lib\/lcdproc\//g" -i "$pkgdir/etc/LCDd.conf"
    install -Dm644 "$srcdir/lcdd.service" "$pkgdir/usr/lib/systemd/system/lcdd.service"
}
