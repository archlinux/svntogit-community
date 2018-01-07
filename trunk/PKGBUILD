# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: John Gerritse <john.gerritse@gmail.com>

pkgname=atop
pkgver=2.3.0
pkgrel=2
pkgdesc='A system and process level monitor'
arch=('x86_64')
url='http://www.atoptool.nl/'
license=('GPL')
depends=('ncurses' 'sh' 'zlib' 'cron')
source=("https://www.atoptool.nl/download/atop-${pkgver/_/-}.tar.gz")
sha512sums=('51cc868545403cab439a66cc38fe9324c6ff7537e6dad5271fa3f0a22cbad471b0e15186d4f78f0080129301ba0a59e0c1cd1cc694bc3a4f982118a8d0cae429')

build() {
    cd "$pkgname-$pkgver"
    make
}

package() {
    cd "$pkgname-$pkgver"
    make DESTDIR="$pkgdir" systemdinstall SBINPATH=/usr/bin
}
