# Maintainer: Orhun Parmaksız <orhun@archlinux.org>
# Contributor: Igor Dyatlov <dyatlov.igor@protonmail.com>

pkgname=rnote
pkgver=0.5.5
_gitcommit=1d42ff8fb8d58e6ff58d3678bc3c17a2aba805a1
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
  "${pkgname}-piet-gpu::git+https://github.com/flxzt/piet-gpu"
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
  git config submodule."piet-gpu".url "${srcdir}/${pkgname}"-piet-gpu
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
