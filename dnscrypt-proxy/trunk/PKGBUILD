# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Techlive Zheng <techlivezheng at gmail dot com>
# Contributor: peace4all <markspost at rocketmail dot com>

pkgname=dnscrypt-proxy
pkgver=2.1.4
_commit=8e043f435d919912e46ac9b7d2beddcfdc8aab70  # refs/tags/2.1.4
pkgrel=2
pkgdesc="A flexible DNS proxy, with support for encrypted DNS protocols"
arch=(x86_64)
url="https://github.com/DNSCrypt/dnscrypt-proxy"
license=(ISC)
depends=(glibc)
makedepends=(git go)
optdepends=('python-urllib3: for generate-domains-blocklist')
backup=(
  etc/$pkgname/$pkgname.toml
  etc/$pkgname/allowed-ips.txt
  etc/$pkgname/allowed-names.txt
  etc/$pkgname/blocked-ips.txt
  etc/$pkgname/blocked-names.txt
  etc/$pkgname/cloaking-rules.txt
  etc/$pkgname/forwarding-rules.txt
)
# NOTE: disabled until gcc is fixed to produce reproducible bytecode for go
options=(!lto)
source=(
  git+https://github.com/dnscrypt/$pkgname#tag=$_commit?signed
  $pkgname.service
  $pkgname.socket
  $pkgname-$pkgver-configuration.patch::https://github.com/dvzrv/dnscrypt-proxy/commit/0dfd620f36c6d5e411933299d8a1481c67da827b.patch
)
sha512sums=('SKIP'
            '6dd1ad7946c8903e0b91658a3680d5cd8d89e8c2177d23ad97b166312fbab649a22599542c94612dec46329e3bba3a55d1488b5228705a85c38565b7dfea54a5'
            '56a56e87032da9316b392b0613124b0743673041596c717005541ae9b3994c7fc16c02497ea773d321f45d8e0f9ea8fda00783062cef4d5c8277b5b6f7cb10d5'
            '6a28226fae15490115a88e93032f8eb09203f7b2d5b89104e1cc8066eaf72b1bc759d6f8a780a0eca2dc1e0db7deae4798c913d500a86105aff2d48759c154bc')
validpgpkeys=('54A2B8892CC3D6A597B92B6C210627AABA709FE1') # Frank Denis (Jedi/Sector One) <pgp@pureftpd.org

prepare() {
  cd $pkgname
  patch -Np1 -i ../$pkgname-$pkgver-configuration.patch
}

build() {
  cd $pkgname/$pkgname
  export CGO_CPPFLAGS="$CPPFLAGS"
  export CGO_CFLAGS="$CFLAGS"
  export CGO_CXXFLAGS="$CXXFLAGS"
  export CGO_LDFLAGS="$LDFLAGS"
  export GOFLAGS="-buildmode=pie -trimpath -ldflags=-linkmode=external -mod=readonly -modcacherw"
  go build
}

package() {
  local _config

  cd $pkgname
  # executable
  install -vDm 755 $pkgname/$pkgname -t "$pkgdir/usr/bin/"
  # config files
  install -vDm 644 $pkgname/example-$pkgname.toml "$pkgdir/etc/$pkgname/$pkgname.toml"
  for _config in {{allowed,blocked}-{ips,names},{cloaking,forwarding}-rules,captive-portals}.txt; do
    install -vDm 644 $pkgname/example-$_config "$pkgdir/etc/$pkgname/$_config"
  done
  # utils
  install -vDm 644 utils/generate-domains-blocklist/*.{conf,txt} -t "$pkgdir/usr/share/$pkgname/utils/generate-domains-blocklist"
  install -vDm 755 utils/generate-domains-blocklist/generate-domains-blocklist.py "$pkgdir/usr/bin/generate-domains-blocklist"
  # systemd service/socket
  install -vDm 644 ../$pkgname.{service,socket} -t "$pkgdir/usr/lib/systemd/system/"
  # license
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
  # docs
  install -vDm 644 {ChangeLog,README.md} -t "$pkgdir/usr/share/doc/$pkgname"
}
# vim:set ts=2 sw=2 et:
