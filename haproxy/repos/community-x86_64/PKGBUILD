# $Id$
# Maintainer:  Bartłomiej Piotrowski <bpiotrowski@archlinux.org>

pkgname=haproxy
pkgver=1.6.1
pkgrel=1
pkgdesc='Reliable, high performance TCP/HTTP load balancer'
arch=('i686' 'x86_64')
url='http://haproxy.org/'
license=('GPL')
depends=('openssl' 'pcre' 'zlib' 'lua')
backup=('etc/haproxy/haproxy.cfg')
install=haproxy.install
source=(http://haproxy.org/download/${pkgver%.*}/src/haproxy-$pkgver.tar.gz
        haproxy.cfg)
md5sums=('7343def2af8556ebc8972a9748176094'
         '7e41518332eeae70fa30dc30861c17c8')

prepare() {
  cd $pkgname-$pkgver
  sed -i 's:/usr/sbin/haproxy:/usr/bin/haproxy:' src/haproxy-systemd-wrapper.c
}

build() {
  cd $pkgname-$pkgver
  make CPU=generic TARGET=linux2628 \
    USE_GETADDRINFO=1 \
    USE_OPENSSL=1 \
    USE_PCRE=1 USE_PCRE_JIT=1 \
    USE_ZLIB=1 \
    USE_LUA=1

  for contrib in halog iprange systemd; do
    make -C contrib/$contrib SBINDIR=/usr/bin
  done
}

package() {
  cd $pkgname-$pkgver
  make PREFIX="$pkgdir"/usr \
    SBINDIR="$pkgdir"/usr/bin \
    DOCDIR="$pkgdir"/usr/share/$pkgname \
    install

  for contrib in halog iprange; do
    install -Dm755 contrib/$contrib/$contrib "$pkgdir"/usr/bin/$contrib
  done

  install -Dm644 ../haproxy.cfg "$pkgdir"/etc/haproxy/haproxy.cfg
  install -Dm644 contrib/systemd/haproxy.service \
    "$pkgdir"/usr/lib/systemd/system/haproxy.service

  install -d "$pkgdir"/usr/share/haproxy/examples/errorfiles
  install -m644 examples/*.cfg "$pkgdir"/usr/share/haproxy/examples/
  install -m644 examples/errorfiles/*.http \
    "$pkgdir"/usr/share/haproxy/examples/errorfiles/

  install -Dm644 examples/haproxy.vim \
    "$pkgdir"/usr/share/vim/vimfiles/syntax/haproxy.vim
}
