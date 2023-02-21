# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lukas Grossar <lukas.grossar@gmail.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>
# Contributor: Wayne Cheng <waynethecheng@gmail.com>
# Contributor: Matthias Lisin <ml@visu.li>

pkgname=helm
pkgver=3.11.1
pkgrel=1
pkgdesc="The Kubernetes Package Manager"
arch=("x86_64")
url="https://github.com/helm/helm"
license=("Apache")
depends=('glibc')
makedepends=("go" "git")
options=("!lto")
#_commit=1addefbfe665c350f4daf868a9adc5600cc064fd
#source=("git+https://github.com/helm/helm.git#commit=${_commit}?signed")
source=("git+https://github.com/helm/helm.git#tag=v${pkgver}?signed")
validpgpkeys=('672C657BE06B4B30969C4A57461449C25E36B98E'
              'CABAA8D44DFACA14791FBE9892C44A3D421FF7F9'
              '967F8AC5E2216F9F4FD270AD92AA783CBAAE8E3B'
              'F1261BDE929012C8FF2E501D6EA5D7598529A53E')
sha256sums=('SKIP')

pkgver() {
  cd "${pkgname}"
  git describe --tags | sed 's/^v//;s/-/+/g'
}

prepare() {
  cd "${pkgname}"
  go mod tidy -compat=1.17
}

build() {
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    export CGO_CFLAGS="$CFLAGS"
    export CGO_CXXFLAGS="$CXXFLAGS"
    export CGO_CPPFLAGS="$CPPFLAGS"
    make EXT_LDFLAGS="-linkmode external" GOFLAGS="-buildmode=pie -trimpath"
}

check(){
    cd "${pkgname}"
    export CGO_LDFLAGS="$LDFLAGS"
    export CGO_CFLAGS="$CFLAGS"
    export CGO_CXXFLAGS="$CXXFLAGS"
    export CGO_CPPFLAGS="$CPPFLAGS"
    make LDFLAGS="-s -w -linkmode external" GOFLAGS="-buildmode=pie -trimpath" test-unit
}

package(){
    cd "${pkgname}"
    install -Dm755 bin/helm -t "$pkgdir/usr/bin"
    bin/helm completion bash | install -Dm644 /dev/stdin "$pkgdir/usr/share/bash-completion/completions/helm"
    bin/helm completion zsh | install -Dm644 /dev/stdin "$pkgdir/usr/share/zsh/site-functions/_helm"
}
