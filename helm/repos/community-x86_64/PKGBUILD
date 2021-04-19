# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lukas Grossar <lukas.grossar@gmail.com>
# Contributor: Ivan Shapovalov <intelfx@intelfx.name>
# Contributor: Wayne Cheng <waynethecheng@gmail.com>
# Contributor: Matthias Lisin <ml@visu.li>

pkgname=helm
pkgver=3.5.4
pkgrel=1
pkgdesc="The Kubernetes Package Manager"
arch=("x86_64")
url="https://helm.sh/"
license=("Apache")
depends=('glibc')
makedepends=("go" "git")
_commit=1b5edb69df3d3a08df77c9902dc17af864ff05d1
#source=("git+https://github.com/helm/helm.git#commit=${_commit}?signed")
source=("git+https://github.com/helm/helm.git#tag=v${pkgver}?signed")
validpgpkeys=('672C657BE06B4B30969C4A57461449C25E36B98E'
              'CABAA8D44DFACA14791FBE9892C44A3D421FF7F9'
              '967F8AC5E2216F9F4FD270AD92AA783CBAAE8E3B')
sha256sums=('SKIP')

pkgver() {
  cd "${pkgname}"
  git describe --tags | sed 's/^v//;s/-/+/g'
}

prepare() {
  cd "${pkgname}"
  go mod tidy

  # update test expectation for new template error string
  git cherry-pick -n f57c01cd9365d7f50a7e3d69b8c75a687392e74c
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
