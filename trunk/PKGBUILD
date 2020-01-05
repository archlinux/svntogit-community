# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: John Gerritse <john.gerritse@gmail.com>

pkgname=atop
pkgver=2.5.0
pkgrel=3
pkgdesc='A system and process level monitor'
arch=('x86_64')
url='https://www.atoptool.nl/'
license=('GPL')
depends=('ncurses' 'sh' 'zlib')
backup=('etc/default/atop')
source=("https://www.atoptool.nl/download/atop-${pkgver/_/-}.tar.gz"
        'atop.default')
sha512sums=('675bbd902d8fe584b1ff47c275ee06d7bfe9127fadf79825ca64bbb6bcb6c34cab485e0686854d805bbdfaf69ebb40d790f7cc00c788544bff73b49c3d24dc08'
            'ed43e68f5d2acd7a9ed0a6df703a1a79b5a6b793e16ab8371463b37e5f16894246af26d178b56625f5e0b3289e2e50c42215da0c57c32ed0ddddaf2178c4d9d0')

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
    # enable atop-rotate.timer by default
    install -dm755 "$pkgdir/usr/lib/systemd/system/timers.target.wants"
    ln -s ../atop-rotate.timer \
        "$pkgdir/usr/lib/systemd/system/timers.target.wants/atop-rotate.timer"
}
