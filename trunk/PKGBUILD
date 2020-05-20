pkgname=maturin
pkgver=0.8.1
pkgrel=1

pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)

depends=(gcc-libs libdbus-1.so rust)
makedepends=(git)

source=(git+https://github.com/PyO3/maturin#tag=v0.8.1?signed)
sha256sums=('SKIP')
validpgpkeys=('07515D832489235391FD5799305BDEA95BCA5CBF')

build() {
  cd maturin
  cargo build --release --locked --all-features
}

package() {
  cd maturin
  install -Dm755 target/release/maturin "$pkgdir"/usr/bin/maturin
}
