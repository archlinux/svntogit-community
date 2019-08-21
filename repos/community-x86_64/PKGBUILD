# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer:  TDY <tdy@gmx.com>
# Contributor: Grigorios Bouzakis <grbzks[at]gmail[dot]com>

pkgname=tmux
pkgver=2.9_a
pkgrel=4
pkgdesc='A terminal multiplexer'
url='https://github.com/tmux/tmux/wiki'
arch=('x86_64')
license=('BSD')
depends=('ncurses' 'libevent' 'libutempter')
source=("https://github.com/tmux/tmux/releases/download/${pkgver/_/}/tmux-${pkgver/_/}.tar.gz"
	'0001-fix-sizing.patch'
        '0002-xterm-348.patch'
	'LICENSE')
sha256sums=('839d167a4517a6bffa6b6074e89a9a8630547b2dea2086f1fad15af12ab23b25'
            '74c89e7c85622c44a07fdce1eefd021dbb0e484a02f7da210ae3ebfa5fdd2fe4'
            '4405816aa3bc1cab7f2bd504fd3aac40d434151171c3d79e1ee88b65103b0600'
            'b5de80619e4884ced2dfe0a96020e85dcfb715a831ecdfdd7ce8c97b5a6ff2cc')

prepare() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	patch -Np1 < ../0001-fix-sizing.patch
	patch -Np1 < ../0002-xterm-348.patch
}

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
