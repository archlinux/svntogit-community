# Maintainer: Jerome Leclanche <jerome@leclan.ch>

pkgname=foliate
pkgver=2.6.3
pkgrel=1
pkgdesc="A simple and modern GTK eBook reader"
arch=("x86_64")
url="https://johnfactotum.github.io/foliate/"
license=("GPL3")
depends=("gjs" "iso-codes" "webkit2gtk")
makedepends=("meson" "ninja" "gettext")
optdepends=(
	"dictd: Offline dictionary support"
	"espeak-ng: Text-to-speech support; also voice package needed"
	"festival: Text-to-speech support; also voice package needed"
	"gspell: Spell-checking support"
	"hyphen: Auto-hyphenation support"
	"tracker"
)
source=("$pkgname-$pkgver.tar.gz"::"https://github.com/johnfactotum/foliate/archive/$pkgver.tar.gz")
sha256sums=("de685facecb1d014c6041dbad75a5609948a0b18b97c74e31e3a1722bccafbe4")


build() {
	cd "$srcdir/$pkgname-$pkgver"
	meson build --prefix=/usr
	ninja -C build
}

package() {
	cd "$srcdir/$pkgname-$pkgver"
	DESTDIR="$pkgdir" ninja -C build install
	ln -sv com.github.johnfactotum.Foliate "$pkgdir/usr/bin/foliate"
}
