# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Techlive Zheng <techlivezheng at gmail dot com>
# Contributor: peace4all <markspost at rocketmail dot com>

pkgname=dnscrypt-proxy
pkgver=2.0.34
pkgrel=1
pkgdesc="DNS proxy, supporting encrypted DNS protocols such as DNSCrypt v2 and DNS-over-HTTPS"
arch=('x86_64')
url="https://dnscrypt.info"
license=('custom:ISC')
depends=('glibc')
makedepends=('git' 'go-pie')
optdepends=('python-urllib3: for generate-domains-blacklist')
install="${pkgname}.install"
backup=("etc/${pkgname}/${pkgname}.toml"
        "etc/${pkgname}/blacklist.txt"
        "etc/${pkgname}/cloaking-rules.txt"
        "etc/${pkgname}/forwarding-rules.txt"
        "etc/${pkgname}/ip-blacklist.txt"
        "etc/${pkgname}/whitelist.txt"
)
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/jedisct1/${pkgname}/archive/${pkgver}.tar.gz"
        "${pkgname}.service"
        "${pkgname}.socket"
        'configuration.diff')
sha512sums=('b48bbedbd5fea5514669ff5593ecd0aee083979c3030fe775558441ee2c398206eba786b9497022c3fab08fe7ee49dcc5205303629834f8fe65d7246e3352381'
            'aa871927bbc37d0c629e75a39cbfe50ce6062a19d7fe5b61895c604d6a480ba8f484cf207943c6ee7bf2dc3c7799d8f7a2b1ea5c8e586920c97730a7c503985e'
            '56a56e87032da9316b392b0613124b0743673041596c717005541ae9b3994c7fc16c02497ea773d321f45d8e0f9ea8fda00783062cef4d5c8277b5b6f7cb10d5'
            '456a81906c9713f7b9bdc6e152d3688899da6f760758fce91a9c625da3d7286bf0fd1d54419a57aa5ec1d9d50e1d2db32b6d5f36c2f265e227dc7e8eef65cfdd')

prepare() {
  cd "$pkgname-$pkgver"
  patch -Np1 -i ../configuration.diff
  # create empty ip-blacklist.txt
  touch "${pkgname}/ip-blacklist.txt"
}

build() {
  cd "$pkgname-$pkgver/${pkgname}"
  go build -ldflags="-linkmode external -extldflags ${LDFLAGS} -s -w"
}

package() {
  cd $pkgname-$pkgver
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
