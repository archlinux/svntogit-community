# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Techlive Zheng <techlivezheng at gmail dot com>
# Contributor: peace4all <markspost at rocketmail dot com>

pkgname=dnscrypt-proxy
pkgver=2.0.44
pkgrel=1
pkgdesc="DNS proxy, supporting encrypted DNS protocols such as DNSCrypt v2 and DNS-over-HTTPS"
arch=('x86_64')
url="https://github.com/DNSCrypt/dnscrypt-proxy"
license=('ISC')
depends=('glibc')
makedepends=('git' 'go')
optdepends=('python-urllib3: for generate-domains-blacklist')
install="${pkgname}.install"
backup=("etc/${pkgname}/${pkgname}.toml"
        "etc/${pkgname}/blacklist.txt"
        "etc/${pkgname}/cloaking-rules.txt"
        "etc/${pkgname}/forwarding-rules.txt"
        "etc/${pkgname}/ip-blacklist.txt"
        "etc/${pkgname}/whitelist.txt"
)
source=("git+https://github.com/jedisct1/${pkgname}#tag=${pkgver}?signed"
        "${pkgname}.service"
        "${pkgname}.socket"
        "${pkgname}-${pkgver}-configuration.patch::https://github.com/dvzrv/dnscrypt-proxy/commit/23baf327e249e2577e7e2f8c25b36fc579caa8c9.patch")
sha512sums=('SKIP'
            '49a9e7ab55e3d5a61017ab2d3a9d8baa503a7737b3b23402d1685f3fda2b59c5e08810bb18be30b2f099da7fa8686ce1bb4052cdd705e9397fd40b663bef3f21'
            '56a56e87032da9316b392b0613124b0743673041596c717005541ae9b3994c7fc16c02497ea773d321f45d8e0f9ea8fda00783062cef4d5c8277b5b6f7cb10d5'
            'b5d5cdd1391670a99f1817dc0a6f8b30300b43a1db49e1e646e09398deac79117036f1eb07f18cfb96a6718e7bddd3cb380acf1c270adce722de97b979d4d5f5')
validpgpkeys=('54A2B8892CC3D6A597B92B6C210627AABA709FE1') # Frank Denis (Jedi/Sector One) <pgp@pureftpd.org

prepare() {
  mv -v "${pkgname}" "${pkgname}-${pkgver}"
  cd "$pkgname-$pkgver"
  patch -Np1 -i "../${pkgname}-${pkgver}-configuration.patch"
  # create empty ip-blacklist.txt
  touch "${pkgname}/ip-blacklist.txt"
}

build() {
  cd "$pkgname-$pkgver/${pkgname}"
  export CGO_CPPFLAGS="${CPPFLAGS}"
  export CGO_CFLAGS="${CFLAGS}"
  export CGO_CXXFLAGS="${CXXFLAGS}"
  export CGO_LDFLAGS="${LDFLAGS}"
  export GOFLAGS="-buildmode=pie -trimpath -mod=readonly -modcacherw"
  go build
}

package() {
  cd "$pkgname-$pkgver"
  # executable
  install -vDm 755 "${pkgname}/${pkgname}" -t "${pkgdir}/usr/bin/"
  # configuration
  install -vDm 644 "${pkgname}/example-${pkgname}.toml" \
    "${pkgdir}/etc/${pkgname}/${pkgname}.toml"
  install -vDm 644 "${pkgname}/example-blacklist.txt" \
    "${pkgdir}/etc/${pkgname}/blacklist.txt"
  install -vDm 644 "${pkgname}/example-cloaking-rules.txt" \
    "${pkgdir}/etc/${pkgname}/cloaking-rules.txt"
  install -vDm 644 "${pkgname}/example-forwarding-rules.txt" \
    "${pkgdir}/etc/${pkgname}/forwarding-rules.txt"
  install -vDm 644 "${pkgname}/ip-blacklist.txt" \
    "${pkgdir}/etc/${pkgname}/ip-blacklist.txt"
  install -vDm 644 "${pkgname}/example-whitelist.txt" \
    "${pkgdir}/etc/${pkgname}/whitelist.txt"
  # utils
  install -vDm 644 utils/generate-domains-blacklists/*.{conf,txt} \
    -t "${pkgdir}/usr/share/${pkgname}/utils/generate-domains-blacklists"
  install -vDm 755 utils/generate-domains-blacklists/generate-domains-blacklist.py \
    "${pkgdir}/usr/bin/generate-domains-blacklist"
  # systemd service/socket
  install -vDm 644 "../${pkgname}."{service,socket} \
    -t "${pkgdir}/usr/lib/systemd/system/"
  # license
  install -vDm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  # docs
  install -vDm 644 {ChangeLog,README.md} \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}
# vim:set ts=2 sw=2 et:
