# Maintainer: Giancarlo Razzolini <grazzolini@archlinux.org>
# Contributor: Guillaume ALAUX <guillaume@archlinux.org>
# Contributor: Allan McRae <allan@archlinux.org>
# Contributor: fancris3 <fancris3 at gmail.com>
# Contributor: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=terminator
pkgver=2.1.3
pkgrel=3
pkgdesc='Terminal emulator that supports tabs and grids'
arch=('any')
url='https://github.com/gnome-terminator/terminator'
license=('GPL2')
depends=('gsettings-desktop-schemas' 'libkeybinder3' 'libnotify' 'python-cairo' 'python-configobj'
         'python-dbus' 'python-psutil' 'python-gobject' 'vte3' 'xdg-utils')
makedepends=('intltool' 'python-pytest-runner' 'python-setuptools' 'python-wheel')
source=(${url}/releases/download/v${pkgver}/${pkgname}-${pkgver}.tar.gz{,.asc}
        0001-fixed-validate-module-import-for-newer-version-of-co.patch
        https://github.com/gnome-terminator/terminator/commit/8ae6f93f.patch)

validpgpkeys=('6FBDB41587919A0F4BA96EBA9A358BAB04A4ED27'  #Markus Frosch <markus@lazyfrosch.de>
              'D11A7596F61705480C711598F2FAC7C7BAE930A5') #Matt Rose <mattrose@folkwolf.net>
sha512sums=('79bdf22f068e14cd63e527f3671cd7b06f2685ef12594870aee170f858a8eabb21e63e7a9ef41fcc664e9b34e8f24b08e998de686be7bf47e0d4315c1224bb8e'
            'SKIP'
            'da609bbb1f2fce64bd345ec43c05f6b8d76046cfbd1be764d6fcd555d306dfca1dd5786b0fc65c0984e49a85454c9eeabf5a1f8c960412c14a97c5350912f8a9'
            '62d513a4715388aa9e83252f53de56950e6e60ba4ab42812dbc41ff3eb874479dca894489c8e88414414b93bd2f25365b6aee8434e1fdc0043c9cce4bb6355a7')
b2sums=('39ec3ca049d5fb532e420ab48a609bd254d626e1949b7c659c85a451054ec4c6f59c89940b2a618131933090fa70aa4441ab88abf2a302d84f6c9b2c61bb22c6'
        'SKIP'
        '7cde90cefde34346ef20b50ebd5b930cb47df650c649e199adbb1b6235db0b40c0c2ad2b0e30bc764d52469357ce0b0424648f70da93b10d39ed0793cbbfe648'
        '3c42e22fa321423e8e4e59a9ed5c943599833b8683005f0c4a451b803a01f5dc8e56d67885b643238320c2b360c3ef122385c48050723cf1edcce4811157fc00')

prepare () {
    cd "${pkgname}-${pkgver}"

    #Fix for python configobj validate
    patch -Np1 < $srcdir/0001-fixed-validate-module-import-for-newer-version-of-co.patch
    # Fix context menu keybinding
    patch -p1 < ../8ae6f93f.patch
}

build() {
    cd "${pkgname}-${pkgver}"

    python setup.py build
}

package() {
    cd "${pkgname}-${pkgver}"

    python setup.py install --skip-build --root="${pkgdir}" --optimize=1

    rm -f "${pkgdir}/usr/share/icons/hicolor/icon-theme.cache"
}
