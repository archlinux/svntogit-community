# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.5
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/PyO3/${pkgname}/archive/refs/tags/v${pkgver}.tar.gz)
sha512sums=('1db5cdeae9e8e7bf1ef5aa7b6ce9ad1030e86ecd21e0e5b7b263e0f0a850bc559f26dbb58fee902c3f297d0e445c67cbf35a2a390ad2c27a271491083a4a8114')
b2sums=('d04c65a017ad42659d7321143a11630b65a9064a3a11119ccef21c57f56a46fe2db6846b500a2004b8878b788df9e43b010502563fe3d21a6dde5c81a5225dff')

prepare() {
  cd ${pkgname}-${pkgver}
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd ${pkgname}-${pkgver}
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so libdbus-1.so)

  cd ${pkgname}-${pkgver}
  install -vDm 755 target/release/maturin -t "${pkgdir}/usr/bin"
  install -vDm 644 {Changelog,Readme}.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}
