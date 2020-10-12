# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Anatol Pomozov
# Contributor: kpcyrd <git@rxv.cc>
# Contributor: Frederik “Freso” S. Olesen <freso.dk@gmail.com>
# Contributor: Ian Naval <ianonavy@gmail.com>

pkgname=go-ipfs
pkgver=0.7.0
pkgrel=1

pkgdesc='A peer-to-peer hypermedia distribution protocol'
url='https://ipfs.io/'
arch=(x86_64)
license=(MIT)

depends=(glibc)
optdepends=('fuse2: for mounting/advanced use')
makedepends=(go git)

source=(go-ipfs-$pkgver.tar.gz::https://github.com/ipfs/go-ipfs/releases/download/v$pkgver/go-ipfs-source.tar.gz
        ipfs.service
        ipfs@.service)
noextract=(go-ipfs-$pkgver.tar.gz)

sha512sums=('46ac79e5a0779bad298a3a0d201fb24408951523554cfa0223f3c50bf402a2bcaac9ec4d911f02799a6d77447127f33cb4f85a234fff40d6831b992e8a094c38'
            '1a6bc7fffc3c3640cda3f33c107424edd698c62bd8509731856b8827ea18be1a1845ef0d5ca15325d48d7d871a78daacc011ff9eacea926bc35899850990c1c6'
            'aed168a35228c4f873e0040d1412f3568bfe1ad1e94ffb8b1a2507058daaf75d7346381d299cf9f0b91951b21553170249ff5f45d5fc060e711cf628ab5e5aad')

prepare() {
  mkdir -p go-ipfs
  tar -C go-ipfs -xf go-ipfs-$pkgver.tar.gz
}

build() {
  cd go-ipfs

  export CGO_LDFLAGS="$LDFLAGS"
  export CGO_CFLAGS="$CFLAGS"
  export CGO_CPPFLAGS="$CPPFLAGS"
  export CGO_CXXFLAGS="$CXXFLAGS"
  export GOFLAGS="-buildmode=pie -trimpath -modcacherw"
  make build
}

package() {
  cd go-ipfs
  install -Dm 755 cmd/ipfs/ipfs "$pkgdir/usr/bin/ipfs"
  install -Dm 644 "$srcdir"/ipfs.service "$pkgdir/usr/lib/systemd/user/ipfs.service"
  install -Dm 644 "$srcdir"/ipfs@.service "$pkgdir/usr/lib/systemd/system/ipfs@.service"
  install -Dm 644 misc/completion/ipfs-completion.bash "$pkgdir/usr/share/bash-completion/completions/ipfs"
  install -Dm 644 -t "$pkgdir/usr/share/licenses/$pkgname/MIT" LICENSE-MIT
  install -Dm 644 -t "$pkgdir/usr/share/licenses/$pkgname/APACHE" LICENSE-APACHE
  install -Dm 644 -t "$pkgdir/usr/share/doc/$pkgname" README.md
}
