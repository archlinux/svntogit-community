# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer:  TDY <tdy@gmx.com>
# Contributor: Grigorios Bouzakis <grbzks[at]gmail[dot]com>

pkgname=tmux
pkgver=3.1_b
pkgrel=2
pkgdesc='A terminal multiplexer'
url='https://github.com/tmux/tmux/wiki'
arch=('x86_64')
license=('BSD')
depends=('ncurses' 'libevent' 'libutempter')
source=("https://github.com/tmux/tmux/releases/download/${pkgver/_/}/tmux-${pkgver/_/}.tar.gz"
        '0001-OpenBSD-6.8-errata-003.patch')
sha256sums=('d93f351d50af05a75fe6681085670c786d9504a5da2608e481c47cf5e1486db9'
            '3bae2afa48f3832f577f9ade513993d84738d594a1dd193fd22d80d0864d8a97')

prepare() {
	cd "$srcdir/$pkgname-${pkgver/_/}"

	patch -Np1 < ../0001-OpenBSD-6.8-errata-003.patch
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
	install -D -m0644 COPYING "$pkgdir/usr/share/licenses/tmux/LICENSE"
}
