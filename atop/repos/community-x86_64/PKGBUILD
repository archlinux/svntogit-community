# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: John Gerritse <john.gerritse@gmail.com>

pkgname=atop
pkgver=2.4.0
pkgrel=3
pkgdesc='A system and process level monitor'
arch=('x86_64')
url='https://www.atoptool.nl/'
license=('GPL')
depends=('ncurses' 'sh' 'zlib' 'cron')
backup=('etc/default/atop')
source=("https://www.atoptool.nl/download/atop-${pkgver/_/-}.tar.gz"
        'atop.default'
        'https://github.com/Atoptool/atop/commit/1e93ac6a8e486dfda633af049c950040020373c9.patch')
sha512sums=('2d0bbecc13bd64427263372b50f50d3278d1e0401e7f2eefe6ff20a874da6315271c885cef3492cde60a2955d1c8db4d8522c3374edcedf1a6992b8fa97c8f18'
            '472a43abfe4bab9169ffce0f365547d646c6a4edb43b4092e893541d6641832cabcf9d8c9ab0332018854d9de5cf2d88a66cdcc5aaa75702cffd83ccb917fc34'
            'd2ee979b0dda1555940f6ee46af9c1c824a5e17356018b5e7dd779cdd9a91f060876f0cbca5a48e8275c92a3a20b513750709fb2461288943fe5423603b96152')

prepare() {
    cd "$pkgname-$pkgver"
    patch -p1 -i "$srcdir/1e93ac6a8e486dfda633af049c950040020373c9.patch"
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
