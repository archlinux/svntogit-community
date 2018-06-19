# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: John Gerritse <john.gerritse@gmail.com>

pkgname=atop
pkgver=2.3.0
pkgrel=3
pkgdesc='A system and process level monitor'
arch=('x86_64')
url='http://www.atoptool.nl/'
license=('GPL')
depends=('ncurses' 'sh' 'zlib' 'cron')
backup=('etc/default/atop')
source=("https://www.atoptool.nl/download/atop-${pkgver/_/-}.tar.gz"
        'atop.default'
        'a88a54107142d057e36be15285c972031a0e8c0a.patch'
        '96287919c311a17ff3c5e3d4b5ebb4507a8ddadf.patch')
sha512sums=('51cc868545403cab439a66cc38fe9324c6ff7537e6dad5271fa3f0a22cbad471b0e15186d4f78f0080129301ba0a59e0c1cd1cc694bc3a4f982118a8d0cae429'
            '472a43abfe4bab9169ffce0f365547d646c6a4edb43b4092e893541d6641832cabcf9d8c9ab0332018854d9de5cf2d88a66cdcc5aaa75702cffd83ccb917fc34'
            'af408a65bc31af192462bd2eee2870523df545ef5ab3397208e04e9eed299e9cc4c16a55a5fa2ad334a7ca7561ad7e414855decb1f35c189705b2e34d5a5577f'
            '2ccc011dab712909be68f5b0940f42e635944c710839665323594bbc04f729bacbf9494a9cb547fd4020cbf1a7dcf4882f4e8416556d7991ba2e0cbb962d9f94')

prepare() {
    cd "$pkgname-$pkgver"
    patch -p1 -i "$srcdir/a88a54107142d057e36be15285c972031a0e8c0a.patch"
    patch -p1 -i "$srcdir/96287919c311a17ff3c5e3d4b5ebb4507a8ddadf.patch"
}

build() {
    cd "$pkgname-$pkgver"
    make
}

package() {
    cd "$pkgname-$pkgver"
    make DESTDIR="$pkgdir" systemdinstall SBINPATH=/usr/bin
    install -Dm644 "$srcdir/atop.default" "$pkgdir/etc/default/atop"
}
