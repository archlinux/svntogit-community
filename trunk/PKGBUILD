# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Alfredo Palhares <masterkorp@masterkorp.net>

pkgname=hub
pkgver=2.14.2
pkgrel=3

pkgdesc="cli interface for Github"
url="https://hub.github.com"
arch=('x86_64')
license=('MIT')

depends=('git')
makedepends=('go')

source=("hub-$pkgver.tar.gz::https://github.com/github/hub/archive/v$pkgver.tar.gz"
        "fix-tests.patch::https://github.com/github/hub/commit/f1170f982c414ec53ebf35ad3b250226ec18a952.patch")
sha256sums=('e19e0fdfd1c69c401e1c24dd2d4ecf3fd9044aa4bd3f8d6fd942ed1b2b2ad21a'
            'a7d5ab7ea437353b818f4934987455ae9b0d883722015761fac4fe48fd3b5256')
b2sums=('b0ff7bcebca7f4b515acf412b756da8512dad7c89f1976cc749c68d70303ff7172b6817e92c839c1864b55ac137e67cf1c99fa07e09b01fd76ad3d40be8d2163'
        '2fe3848bae8c26d56f8a9fb0fa81902931f70b7ddf7ef31ed0f141c7b1e631561616b38f904a712d5de4d258b4c29bb0758f22763017959849c2f183eb0062d2')

prepare() {
    cd "${pkgname}-${pkgver}"
    patch -Np1 < "$srcdir/fix-tests.patch"
}

build() {
  cd "$srcdir"/hub-$pkgver

  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export CGO_LDFLAGS="${LDFLAGS}"
  export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"

  make
  make man-pages
}

check() {
  cd "$srcdir"/hub-$pkgver

  make test
}

package() {
  cd "$srcdir"/hub-$pkgver

  make PREFIX="$pkgdir"/usr install

  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
  install -Dm644 etc/hub.bash_completion.sh "$pkgdir"/usr/share/bash-completion/completions/hub
  install -Dm644 etc/hub.zsh_completion "$pkgdir"/usr/share/zsh/site-functions/_hub
  install -Dm644 etc/hub.fish_completion "$pkgdir"/usr/share/fish/vendor_completions.d/hub.fish
}
