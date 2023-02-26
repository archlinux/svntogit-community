# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: John K. Luebs <jkl at johnluebs dot tld>

pkgname=tea
pkgver=0.9.2
pkgrel=1
pkgdesc='A command line tool to interact with Gitea servers'
arch=('x86_64')
url='https://gitea.com/gitea/tea'
license=('MIT')
depends=('glibc')
makedepends=('git' 'go')
replaces=('gitea-tea')
options=('!lto')
_commit='fff1af1029a1c63c078e058c9a5c4d3ac7054594'
source=("$pkgname::git+$url#commit=$_commit")
b2sums=('SKIP')

pkgver() {
  cd "$pkgname"

  git describe --tags | sed 's/^v//'
}

prepare() {
  cd "$pkgname"

  # create directory for build output
  mkdir build

  # fix zsh completion
  sed -i "s/\$PROG/tea/" contrib/autocomplete.zsh

  # download dependencies
  export GOPATH="${srcdir}"
  go mod download
}
build() {
  cd "$pkgname"

  # set Go flags
  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export GOPATH="${srcdir}"
  local TAGS=""

  go build -v \
    -buildmode=pie \
    -mod=readonly \
    -modcacherw \
    -ldflags "-compressdwarf=false \
    -linkmode external \
    -extldflags ${LDFLAGS} \
    -X main.Version=${pkgver} \
    -X main.Tags=${TAGS}" \
    -o build \
    .
}

package() {
  cd "$pkgname"

  # binary
  install -vDm755 -t "$pkgdir/usr/bin" build/tea

  # license
  install -vDm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE

  # completions
  install -vDm644 contrib/autocomplete.sh "$pkgdir/usr/share/bash-completion/completions/$pkgname"
  install -vDm644 contrib/autocomplete.zsh "$pkgdir/usr/share/zsh/site-functions/_tea"
}
