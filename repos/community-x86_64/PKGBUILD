# Maintainer: Maxim Baz <$pkgname at maximbaz dot com>
# Contributor: Jorge Araya Navarro <jorge@esavara.cr>

pkgname=goimapnotify
pkgver=2.3.3
pkgrel=1
pkgdesc="Execute scripts on IMAP mailbox changes (new/deleted/updated messages) using IDLE, golang version."
url="https://gitlab.com/shackra/goimapnotify"
license=('GPL3')
arch=('x86_64')
depends=('glibc')
makedepends=('git' 'go')
source=("${pkgname}-${pkgver}.tar.gz::${url}/-/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('3770521fe3c6b41c56b5d9fc3980c5402d3874a366c0e9f8c96093c697d8ee5eba8196b84c6f3f1ad8ac5f8951dd4ef5fac8a0756bdca2e909999fb36f47d1ee')

build() {
    cd "${pkgname}-${pkgver}"

    export CGO_CPPFLAGS="${CPPFLAGS}"
    export CGO_CFLAGS="${CFLAGS}"
    export CGO_CXXFLAGS="${CXXFLAGS}"
    export CGO_LDFLAGS="${LDFLAGS}"
    export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"
    go build -ldflags "-linkmode=external -extldflags=$LDFLAGS"
}

check() {
    cd "${pkgname}-${pkgver}"

    go test ./...
}

package() {
    cd "${pkgname}-${pkgver}"

    install -Dm755 -t "${pkgdir}/usr/bin/" "${pkgname}"
    install -Dm644 -t "${pkgdir}/usr/lib/systemd/user/" goimapnotify@.service
}
