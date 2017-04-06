# $Id$
# Maintainer: BlackEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Bernhard Walle <bernhard.walle@gmx.de>

pkgname=lcdproc
pkgver=0.5.8
pkgrel=1
pkgdesc="Utility to drive one or more LCD (and LCD-like) devices"
arch=('i686' 'x86_64')
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
sha512sums=('98c80b8a55f591da0c6c871e3d6caa06edd8c6b15ca7e536e1c35f5853503621f99fa3834901d228d49c2bd035b2606517c06b868b856c4f940d696001cf222e'
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
