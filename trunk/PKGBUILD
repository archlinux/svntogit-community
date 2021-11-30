# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.3
pkgrel=2
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/PyO3/${pkgname}/archive/refs/tags/v${pkgver}.tar.gz)
sha512sums=('2a568dacf09a01f7198570381079c61c98b1771a2e447cd2077256436a6f9e566828b6e9064c5ca0a7aa8de0e442602ff1940f454503db635bda9682614165ef')
b2sums=('c98de550c99c378e6b9e90118acc7e7b67184455a447165840ceb109611e92c1fc2b1b4512dea16c869f3fa5041c0b8906e5767df6f06d45c308045bc4ad5f47')

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
