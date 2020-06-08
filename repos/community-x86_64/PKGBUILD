# Maintainer: BlackEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Bernhard Walle <bernhard.walle@gmx.de>

pkgname=lcdproc
pkgver=0.5.9
pkgrel=4
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
            'e5e9227f35dbdc4d1d4fb736970a392e374020ad0b99daa393f11717e86bbbe921f25f7d427f4617de1e59b3b03645ff19746648cf1d5e29ca1558886054bd34'
            'f41e54d98d58146d49f2f2b485ea6e86cf6e826014ae54b2157a9a6a6aa857a6577a82bd63a6743970d0106e7a7d2d096ad3e72f59e584af7723717f115eda95')

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
