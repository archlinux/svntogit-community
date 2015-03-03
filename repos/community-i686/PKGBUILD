# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Contributor: Jarek Sedlacek <jareksedlacek@gmail.com>

pkgname=php-mongo
pkgver=1.6.4
pkgrel=1
pkgdesc="Officially supported PHP driver for MongoDB"
arch=("i686" "x86_64")
url="http://www.mongodb.org/display/DOCS/PHP+Language+Center"
license=("APACHE")
depends=("php")
backup=("etc/php/conf.d/mongo.ini")
source=(
	"http://pecl.php.net/get/mongo-$pkgver.tgz"
	"mongo.ini"
)

build() {
	cd mongo-$pkgver
	phpize
	./configure --prefix=/usr --enable-mongo
}

package() {
	cd mongo-$pkgver
	make INSTALL_ROOT="$pkgdir" install
	install -Dm644 "$srcdir/mongo.ini" "$pkgdir/etc/php/conf.d/mongo.ini"
}
sha256sums=('b6ab5f4ade26ea328081c70bba43f048da3d669e536eebb9eb380f9db90dda6d'
            'c89685eee842d5c3a85149a5bb8e310e62bf1a17f94183bb66401593ab2b191b')
