pkgname=maturin
pkgver=0.7.9
pkgrel=1

pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)

depends=(rust)
makedepends=(git)

source=(git+https://github.com/PyO3/maturin#tag=v$pkgver)
sha256sums=(SKIP)

build() {
  cd maturin
  cargo build --release --locked --all-features
}

package() {
  cd maturin
  install -Dm755 target/release/maturin "$pkgdir"/usr/bin/maturin
}
