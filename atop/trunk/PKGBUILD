# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: John Gerritse <john.gerritse@gmail.com>

pkgname=atop
pkgver=2.5.0
pkgrel=1
pkgdesc='A system and process level monitor'
arch=('x86_64')
url='https://www.atoptool.nl/'
license=('GPL')
depends=('ncurses' 'sh' 'zlib' 'cron')
backup=('etc/default/atop')
source=("https://www.atoptool.nl/download/atop-${pkgver/_/-}.tar.gz"
        'atop.default')
sha512sums=('675bbd902d8fe584b1ff47c275ee06d7bfe9127fadf79825ca64bbb6bcb6c34cab485e0686854d805bbdfaf69ebb40d790f7cc00c788544bff73b49c3d24dc08'
            '472a43abfe4bab9169ffce0f365547d646c6a4edb43b4092e893541d6641832cabcf9d8c9ab0332018854d9de5cf2d88a66cdcc5aaa75702cffd83ccb917fc34')

#prepare() {
    #cd "$pkgname-$pkgver"
    #patch -p1 -i "$srcdir/1e93ac6a8e486dfda633af049c950040020373c9.patch"
#}

build() {
    cd "$pkgname-$pkgver"
    make
}

package() {
    cd "$pkgname-$pkgver"
    ## default folder not properly created
    mkdir -p "$pkgdir/etc/default"
    make DESTDIR="$pkgdir" systemdinstall SBINPATH=/usr/bin
    install -Dm644 "$srcdir/atop.default" "$pkgdir/etc/default/atop"
}
