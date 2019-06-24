# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Thomas Dziedzic < gostrc at gmail >

pkgname=python-tornado
pkgver=6.0.3
pkgrel=1
pkgdesc='open source version of the scalable, non-blocking web server and tools'
arch=('x86_64')
url='http://www.tornadoweb.org/'
license=('Apache')
depends=('python')
optdepends=('python-pycurl: for tornado.curl_httpclient'
            'python-twisted: for tornado.platform.twisted')
            # 'python-pycares: an alternative non-blocking DNS resolver'
makedepends=('python-setuptools')
checkdepends=('python-pycurl' 'python-mock' 'python-twisted')
source=("$pkgname-$pkgver.tar.gz::https://github.com/tornadoweb/tornado/archive/v$pkgver.tar.gz")
sha512sums=('8caaa64d14edcb3993dffea3175685d82afb0068a8e8834cbb6eb9e15883fe113bb57cd98d99c25362bef0a6ee2762f2baf24effd645ecd77f035583cc4de756')

export TORNADO_EXTENSION=1

build() {
  cd tornado-$pkgver
  python setup.py build
}

check() {
  # As of 4.5.3, ignoring test failures about resolving "localhost"
  (
    cd tornado-$pkgver
    python setup.py install --root="$PWD/tmp_install" --optimize=1
    export PYTHONPATH="$PWD/tmp_install/usr/lib/python3.7/site-packages:$PYTHONPATH"
    cd tmp_install
    python -m tornado.test.runtests
    python -m tornado.test.runtests --ioloop=tornado.platform.select.SelectIOLoop
    python -m tornado.test.runtests --httpclient=tornado.curl_httpclient.CurlAsyncHTTPClient
    python -m tornado.test.runtests --ioloop_time_monotonic
    python -m tornado.test.runtests --ioloop=tornado.platform.twisted.TwistedIOLoop
    python -m tornado.test.runtests --ioloop=tornado.platform.asyncio.AsyncIOLoop
    python -m tornado.test.runtests --resolver=tornado.netutil.ThreadedResolver
  ) || warning "Tests failed"
}

package() {
  cd tornado-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}
