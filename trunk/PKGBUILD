# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: David Anderson <dave@natulte.net>

pkgname=tailscale
pkgver=1.32.1
pkgrel=1
pkgdesc="A mesh VPN that makes it easy to connect your devices, wherever they are."
arch=("x86_64")
url="https://tailscale.com"
license=("MIT")
makedepends=("git" "go")
depends=("glibc")
backup=("etc/default/tailscaled")
# Important: Check if the version has been published before updating
# curl -s "https://pkgs.tailscale.com/stable/?mode=json"
_commit=f8497daa68ef312f87c6583c41c9975500d5b88e	#refs/tags/v1.32.1^{}
source=("git+https://github.com/tailscale/tailscale.git#commit=${_commit}")
sha256sums=('SKIP')

pkgver() {
  cd "${pkgname}"
  git describe --tags | sed 's/^[vV]//;s/-/+/g'
}

prepare() {
    cd "${pkgname}"
    go mod vendor
}

build() {
    cd "${pkgname}"
    export CGO_CPPFLAGS="${CPPFLAGS}"
    export CGO_CFLAGS="${CFLAGS}"
    export CGO_CXXFLAGS="${CXXFLAGS}"
    export CGO_LDFLAGS="${LDFLAGS}"
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"
    GO_LDFLAGS="\
        -linkmode=external \
        -X tailscale.com/version.Long=${pkgver} \
        -X tailscale.com/version.Short=$(cut -d+ -f1 <<< "${pkgver}") \
        -X tailscale.com/version.GitCommit=${_commit}"
    for cmd in ./cmd/tailscale ./cmd/tailscaled; do
        go build -v -tags xversion -ldflags "$GO_LDFLAGS" "$cmd"
    done
}

#TODO: Figure out why tests are failing
# check() {
#     cd "${pkgname}"
#     go test $(go list ./... | grep -v tsdns_test)
# }

package() {
    cd "${pkgname}"
    install -Dm755 tailscale tailscaled -t "$pkgdir/usr/bin"
    install -Dm644 cmd/tailscaled/tailscaled.defaults "$pkgdir/etc/default/tailscaled"
    install -Dm644 cmd/tailscaled/tailscaled.service -t "$pkgdir/usr/lib/systemd/system"
    install -Dm644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
}
