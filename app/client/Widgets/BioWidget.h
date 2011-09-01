#ifndef BIO_WIDGET_H_
#define BIO_WIDGET_H_

#include <QTextBrowser>
#include <QTextObjectInterface>
#include <QDebug>

/** A specialized QTextBrowser which can insert widgets inline */
#include <QPlainTextDocumentLayout>
class BioWidget : public QTextBrowser {
    Q_OBJECT
public:
    BioWidget( QWidget* parent );
    bool eventFilter( QObject* o, QEvent* e );
    
    void loadImage( const QUrl& );
    void setImageHref( const QUrl& );
    
    void setOnTourVisible( bool, const QUrl& = QUrl());

protected slots:
    void onBioChanged( const QSizeF& size );
    void onAnchorClicked( const QUrl& link );

    void onHighlighted( const QString& url );

protected:
    void insertWidget( QWidget* w );
    class WidgetTextObject* m_widgetTextObject;

    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void mouseMoveEvent( QMouseEvent* event );

    bool sendMouseEvent( QMouseEvent* event );

    enum WidgetProperties { WidgetData = 1 };
    enum { WidgetImageFormat = QTextFormat::UserObject + 1 };
    QWidget* m_currentHoverWidget;

    struct {
        class BannerWidget* onTour;
        class HttpImageWidget* image;
    } ui;
};


#endif //BIO_WIDGET_H_
