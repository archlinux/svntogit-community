# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer:  TDY <tdy@gmx.com>
# Contributor: Grigorios Bouzakis <grbzks[at]gmail[dot]com>

pkgname=tmux
pkgver=2.9
pkgrel=1
pkgdesc='A terminal multiplexer'
url='https://github.com/tmux/tmux/wiki'
arch=('x86_64')
license=('BSD')
depends=('ncurses' 'libevent' 'libutempter')
source=("https://github.com/tmux/tmux/releases/download/$pkgver/tmux-$pkgver.tar.gz"
	'LICENSE')
sha256sums=('34901232f486fd99f3a39e864575e658b5d49f43289ccc6ee57c365f2e2c2980'
            'b5de80619e4884ced2dfe0a96020e85dcfb715a831ecdfdd7ce8c97b5a6ff2cc')

build() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	./configure \
		--prefix=/usr \
		--enable-utempter
	make
}

package() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	make install DESTDIR="$pkgdir"
	install -Dm644 "$srcdir"/LICENSE "$pkgdir/usr/share/licenses/tmux/LICENSE"
}
