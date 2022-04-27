# Maintainer: Maxim Baz <$pkgname at maximbaz dot com>
# Contributor: Jorge Araya Navarro <jorge@esavara.cr>

pkgname=goimapnotify
pkgver=2.3.7
pkgrel=3
pkgdesc="Execute scripts on IMAP mailbox changes (new/deleted/updated messages) using IDLE, golang version."
url="https://gitlab.com/shackra/goimapnotify"
license=('GPL3')
arch=('x86_64')
depends=('glibc')
makedepends=('git' 'go')
source=("${pkgname}-${pkgver}.tar.gz::${url}/-/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('7551ec498c3414448b21bf4202a69bbab8815dd9423638b3adbf31fb2857a008fb6f1ac78e41ce695550931dfe4ba9c49050f3bfcab2d646f37547a7efcdaff7')
options=(!lto)

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
