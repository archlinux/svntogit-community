# Maintainer: Orhun Parmaksız <orhun@archlinux.org>
# Contributor: Igor Dyatlov <dyatlov.igor@protonmail.com>

pkgname=rnote
pkgver=0.5.7
_gitcommit=9d0eea31722257582dcedf809d3ec45ba41d0de6
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
  "${pkgname}-piet-gpu::git+https://github.com/flxzt/piet-gpu"
)
b2sums=('SKIP'
        'SKIP'
        'SKIP'
        'SKIP')
options=('!lto')

prepare() {
  cd "$pkgname-$pkgver"
  git submodule init
  git config submodule."piet".url "${srcdir}/${pkgname}"-piet
  git config submodule."piet-gpu".url "${srcdir}/${pkgname}"-piet-gpu
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
