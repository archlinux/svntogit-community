# Maintainer: Orhun Parmaksız <orhun@archlinux.org>
# Contributor: Igor Dyatlov <dyatlov.igor@protonmail.com>

pkgname=rnote
pkgver=0.5.1
_gitcommit=446eaab064cd1df17a6ebc9bf3a97f3ddf8cace2
pkgrel=1
pkgdesc="A simple drawing application to create handwritten notes"
arch=('x86_64')
url="https://github.com/flxzt/rnote"
license=('GPL3')
depends=('gtk4' 'glib2' 'libadwaita' 'poppler-glib' 'gstreamer' 'alsa-lib')
makedepends=('meson' 'cargo' 'git')
#checkdepends=('appstream-glib')
source=(
  "${pkgname}-${pkgver}::git+$url#commit=$_gitcommit"
  "${pkgname}-piet::git+https://github.com/flxzt/piet"
)
b2sums=('SKIP'
        'SKIP')
options=('!lto')

prepare() {
  cd "$pkgname-$pkgver"
  git submodule init
  git config submodule."piet".url "${srcdir}/${pkgname}"-piet
  git submodule update --init --recursive
}

build() {
  arch-meson "$pkgname-$pkgver" build
  meson compile -C build
}

#check() {
#  meson test -C build
#}

package() {
  meson install -C build --destdir "$pkgdir"
}

# vim: ts=2 sw=2 et:
