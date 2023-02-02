# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Metal A-wing <1 at 233 dot email>

pkgname=deno
pkgver=1.30.1
_commit=000fb83c587a17118d83b990f1d08c98bb9cce2a
pkgrel=1
pkgdesc="A secure runtime for JavaScript and TypeScript"
arch=('x86_64')
url="https://deno.land"
license=('MIT')
options=('!lto')
depends=('gcc-libs')
makedepends=('git' 'python' 'cargo' 'nodejs')
source=("git+https://github.com/denoland/deno.git#commit=$_commit")
sha512sums=('SKIP')

prepare() {
  cd $pkgname
  git submodule update --init --recursive
}

build() {
  cd $pkgname
  cargo build --release
}

check() {
  cd $pkgname
  ./target/release/deno run cli/tests/testdata/run/002_hello.ts
}

package() {
  cd $pkgname
  install -Dm755 target/release/deno "$pkgdir"/usr/bin/deno

  install -dm755 "$pkgdir"/usr/share/bash-completion/completions
  ./target/release/deno completions bash > "$pkgdir"/usr/share/bash-completion/completions/deno
  install -dm755 "$pkgdir"/usr/share/zsh/site-functions
  ./target/release/deno completions zsh > "$pkgdir"/usr/share/zsh/site-functions/_deno
  install -dm755 "$pkgdir"/usr/share/fish/vendor_functions.d
  ./target/release/deno completions fish > "$pkgdir"/usr/share/fish/vendor_functions.d/deno.fish

  install -Dm644 LICENSE.md -t "$pkgdir"/usr/share/licenses/$pkgname/
}
