# Maintainer: BlackEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Bernhard Walle <bernhard.walle@gmx.de>

pkgname=lcdproc
pkgver=0.5.9
pkgrel=5
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
    'lcdproc-0.5.9-fix-fno-common-build.patch'
    'lcdd.service'
    'lcdproc.service'
)
sha512sums=('48e11a587570376b9524591f4c23deace9ac1609b83ba9e17f2a4e950d5598f8f88b580ca01c174ec9c2ef98b1eef7ac274c23ca3541d4d7ff918af0598c6a25'
            '2a230cf311699f5d30a36d73784e9539c6a018b281282f341a167a0f946212a9d156b23efdf7f921f5ed8941f7dc6f68878ec2d87247727bec78230eb04eda0f'
            'f5a37c10be5f51593ef4b5ffc741e262a65f2588958861cc76fdea05209357e69e759c1ae5abf12fe4b8a67150ae800f35e83e745bf078168f0ccbc5d1e9eac3'
            'b77725c5b100d5041b1715fec29d32a2066c5508f3edee3f94970e9df1632aae522ed164163c32acb1139e4fa95dc76a329a307b24c76a41b73bdf844dd7d036')

prepare() {
    cd "$pkgname-$pkgver"
    patch -p1 -i "$srcdir/lcdproc-0.5.9-fix-fno-common-build.patch"
}

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
    install -Dm644 "$srcdir/lcdproc.service" "$pkgdir/usr/lib/systemd/system/lcdproc.service"
}
