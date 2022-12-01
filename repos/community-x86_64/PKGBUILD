# Maintainer: Orhun Parmaksız <orhun@archlinux.org>
# Contributor: Igor Dyatlov <dyatlov.igor@protonmail.com>

pkgname=rnote
pkgver=0.5.8
_gitcommit=fa9e77da36f01cb6df49d431b4ed4837bb97510b
pkgrel=1
pkgdesc="A simple drawing application to create handwritten notes"
arch=('x86_64')
url="https://github.com/flxzt/rnote"
license=('GPL3')
depends=('gtk4' 'glib2' 'libadwaita' 'poppler-glib' 'gstreamer' 'alsa-lib')
makedepends=('meson' 'cargo' 'cmake' 'clang' 'git')
#checkdepends=('appstream-glib')
source=(
  "${pkgname}-${pkgver}::git+$url#commit=$_gitcommit"
  "${pkgname}-ink-stroke-modeler-rs::git+https://github.com/flxzt/ink-stroke-modeler-rs"
  "${pkgname}-piet::git+https://github.com/flxzt/piet"
)
b2sums=('SKIP'
        'SKIP'
        'SKIP')
options=('!lto')

prepare() {
  cd "$pkgname-$pkgver"
  git submodule init
  git config submodule."piet".url "${srcdir}/${pkgname}"-piet
  git config submodule."ink-stroke-modeler-rs".url "${srcdir}/${pkgname}"-ink-stroke-modeler-rs
  git -c protocol.file.allow=always submodule update --init --recursive
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
